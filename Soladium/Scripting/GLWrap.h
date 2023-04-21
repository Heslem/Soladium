#pragma once
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// I don't know, but i think delete it.


static void GLWrap_wrap()
{
	
	mono_add_internal_call("SoladuimAPI.SRender::Vertex2f", &glVertex2f);

}