#include "hzpch.h"
#include "Texture.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Hazel {

    Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::OpenGL:   return CreateRef<OpenGLTexture2D>(width, height);
            case RendererAPI::API::None:     HZ_CORE_ASSERT(false, "RendererAPI::API::None is currently not supported!");  return nullptr;
        }

        HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<Texture2D> Texture2D::Create(const std::string& path)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:     HZ_CORE_ASSERT(false, "RendererAPI::API::None is currently not supported!");  return nullptr;
            case RendererAPI::API::OpenGL:   return CreateRef<OpenGLTexture2D>(path);
        }

        HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}
