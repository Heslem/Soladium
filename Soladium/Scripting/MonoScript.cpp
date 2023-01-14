#include "MonoScript.h"
#include "../Engine.h"
#include <iostream>
#include "GLWrap.h"

static void print() {
	std::cout << "PRINT YEEEAH" << std::endl;
}
static void wrap_close() {
	Engine::getInstance().close();
}

static void wrap_profiler_start(MonoString* name) {
	auto& profiler = Engine::getInstance();
	//profiler.start(mono_string_to_utf8(name));
}

//static Profiler::ProfilerTask wrap_profiler_end() {
//	return .end();
//}

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
				//mono_add_internal_call("SoladuimAPI.SProfiler::End", &wrap_profiler_end);
				

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
