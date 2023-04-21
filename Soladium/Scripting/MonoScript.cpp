#include "MonoScript.h"
#include "../Engine.h"
#include <iostream>
#include "GLWrap.h"

#include "../utils/Keyboard.h"


// TODO: delete

#pragma pack(1)
struct TMono
{
public:
	TMono(Profiler::ProfilerTask* p)
		: time((int)p->time)
	{
		
	}
	int time;
};

// TODO: develop better solution for wrapping methods

static void wrap_close() {
	Engine::getInstance().close();
}

static void wrap_profiler_start(MonoString* name) {
	auto& profiler = Engine::getInstance().getProfiler();
	profiler.start(mono_string_to_utf8(name));
} 

static TMono* wrap_profiler_end() {
	auto& profiler = Engine::getInstance().getProfiler();
	// TODO: fix memory leak.
	return new TMono(profiler.end());
}


MonoScript::MonoScript()
	: m_MonoDomain(nullptr), m_GameAssembly(nullptr), m_GameAssemblyImage(nullptr)
{
}

MonoScript::~MonoScript()
{
	if (m_MonoDomain)
	{
		mono_jit_cleanup(m_MonoDomain);

		// i hope this right solution.
		for (auto const& pair : m_cachedMethodDesc) {
			mono_method_desc_free(pair.second);
		}
		for (auto const& pair : m_cachedMethods) {
			mono_free_method(pair.second);
		}
	}
}

void MonoScript::registerClass(const char* className, const char* ns)
{
	MonoClass* ptrClass = mono_class_from_name(m_GameAssemblyImage, ns, className);
	if (ptrClass)
	{
		if (!m_cachedClasses[className])
			m_cachedClasses[className] = ptrClass;
	}
	else
		throw std::runtime_error(std::string("Registering a non-existing class: ").append(className).c_str());
}

void MonoScript::registerMethodDesc(const char* name)
{
	MonoMethodDesc* ptrMethodDesc = mono_method_desc_new(name, false);
	if (ptrMethodDesc)
	{
		if (!m_cachedMethodDesc[name])
			m_cachedMethodDesc[name] = ptrMethodDesc;
	}
	else
		throw std::runtime_error(std::string("Can't find a methodDecs: ").append(name).c_str());
}


void MonoScript::registerMethod(const char* methodDesc, const char* className)
{
	MonoMethod* ptrMethod = mono_method_desc_search_in_class(m_cachedMethodDesc[methodDesc], m_cachedClasses[className]);
	if (ptrMethod)
	{
		if (!m_cachedMethods[methodDesc])
			m_cachedMethods[methodDesc] = ptrMethod;
	}
	else
		throw std::runtime_error(std::string("Can't find a method"));
}

MonoMethod* MonoScript::getMethod(const char* methodDesc)
{
	MonoMethod* ptrMethod = m_cachedMethods[methodDesc];
	if (ptrMethod)
		return ptrMethod;
	else
		throw std::runtime_error(std::string("Can't find a method"));
}

MonoObject* MonoScript::createMonoObject(const char* className)
{
	return mono_object_new(m_MonoDomain, m_cachedClasses[className]);
}


MonoComponent* MonoScript::createMonoComponent(const std::string& className, const bool& registered)
{
	const char* startDecs = std::string("." + className + ":Start()").c_str();
	const char* updateDecs = std::string("." + className + ":Update()").c_str();
	
	if (!registered)
	{
		registerClass(className.c_str());
		registerMethodDesc(startDecs);
		registerMethodDesc(updateDecs);
		registerMethod(startDecs, className.c_str());
		registerMethod(updateDecs, className.c_str());
	}
	
	return new MonoComponent(MonoComponent::BaseMonoComponentData(getMethod(startDecs), getMethod(updateDecs)), createMonoObject(className.c_str()));
}

void MonoScript::init() 
{
	m_MonoDomain = mono_jit_init("Game");
	if (m_MonoDomain)
	{
		m_GameAssembly = mono_domain_assembly_open(m_MonoDomain, "SoladuimGame.dll");
		if (m_GameAssembly) {

			m_GameAssemblyImage = mono_assembly_get_image(m_GameAssembly);
			if (m_GameAssemblyImage) {
				
				// TODO: make soladuimAPI in another solution

				mono_add_internal_call("SoladuimAPI.SEngine::Close", &wrap_close);

				mono_add_internal_call("SoladuimAPI.SProfiler::Start", &wrap_profiler_start);
				mono_add_internal_call("SoladuimAPI.SProfiler::End", &wrap_profiler_end);

				mono_add_internal_call("SoladuimAPI.SKeyboard::IsKeyPressed", &Keyboard::pressed);


				GLWrap_wrap();

				MonoClass* ptrMainClass = mono_class_from_name(m_GameAssemblyImage, "SoladuimGame", "Game");
				if (ptrMainClass) {
					MonoMethodDesc* ptrMainMethodDesc = mono_method_desc_new(".Game:Run()", false);
					if (ptrMainMethodDesc) {
						MonoMethod* ptrMainMethod = mono_method_desc_search_in_class(ptrMainMethodDesc, ptrMainClass);
						if (ptrMainMethod) {
							MonoObject* ptrExObject = nullptr;
							mono_runtime_invoke(ptrMainMethod, nullptr, nullptr, &ptrExObject);
						}
						
						mono_method_desc_free(ptrMainMethodDesc);
					}
				}
			}
		}
	}
}
