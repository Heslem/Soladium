#include "MonoScript.h"
#include "../Engine.h"
#include <iostream>
#include "GLWrap.h"

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

static void print() {
	std::cout << "PRINT YEEEAH" << std::endl;
}
static void wrap_close() {
	Engine::getInstance().close();
}

static void wrap_profiler_start(MonoString* name) {
	auto& profiler = Engine::getInstance().getProfiler();
	profiler.start(mono_string_to_utf8(name));
} 

static void wrap_profiler_end(TMono& obj) {
	auto& profiler = Engine::getInstance().getProfiler();
	auto* val = profiler.end();
	std::cout << val->time << std::endl;
	obj.time = val->time;
}



#pragma pack(1)
struct TestStruct
{
	int a;
	int b;
};

static TestStruct* wrap_profiler_testStruct() {
	auto* v = new TestStruct();
	v->a = 10;
	v->b = -10;

	return v;
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
	}
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
				
				mono_add_internal_call("SoladuimAPI.Soladuim::Print", &print);
				mono_add_internal_call("SoladuimAPI.SEngine::Close", &wrap_close);
				mono_add_internal_call("SoladuimAPI.SProfiler::Start", &wrap_profiler_start);
				
				mono_add_internal_call("SoladuimAPI.SProfiler::End", &wrap_profiler_end);
				mono_add_internal_call("SoladuimAPI.SProfiler::GetTest", &wrap_profiler_testStruct);
				

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
