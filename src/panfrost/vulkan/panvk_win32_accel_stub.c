/*
 * Copyright 2026 contributors of the manet Windows port
 * SPDX-License-Identifier: MIT
 */

/* win32/no-glslang stub.
 *
 * The common BVH runtime (src/vulkan/runtime/vk_acceleration_structure.c)
 * is only added to the build when glslang is available (it embeds BVH
 * shaders compiled at build time). panvk_physical_device.c's format
 * properties table references vk_acceleration_struct_vtx_format_supported
 * unconditionally, so on targets without glslang (the Windows CI runner)
 * the link fails with an undefined symbol. Provide the self-contained
 * helper here; the switch mirrors the upstream implementation exactly so
 * behavior is identical whenever both files are built (this file is only
 * compiled when the runtime one is not).
 */

#include "vk_acceleration_structure.h"

bool
vk_acceleration_struct_vtx_format_supported(VkFormat format)
{
   switch (format) {
   case VK_FORMAT_R32G32_SFLOAT:
   case VK_FORMAT_R32G32B32_SFLOAT:
   case VK_FORMAT_R32G32B32A32_SFLOAT:
   case VK_FORMAT_R16G16_SFLOAT:
   case VK_FORMAT_R16G16B16_SFLOAT:
   case VK_FORMAT_R16G16B16A16_SFLOAT:
   case VK_FORMAT_R16G16_SNORM:
   case VK_FORMAT_R16G16_UNORM:
   case VK_FORMAT_R16G16B16A16_SNORM:
   case VK_FORMAT_R16G16B16A16_UNORM:
   case VK_FORMAT_R8G8_SNORM:
   case VK_FORMAT_R8G8_UNORM:
   case VK_FORMAT_R8G8B8A8_SNORM:
   case VK_FORMAT_R8G8B8A8_UNORM:
   case VK_FORMAT_A2B10G10R10_UNORM_PACK32:
      return true;
   default:
      return false;
   }
}
