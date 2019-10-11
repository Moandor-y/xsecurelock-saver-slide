#ifndef XSECURELOCK_SAVER_SLIDE_SDLTEXTURE_HPP_
#define XSECURELOCK_SAVER_SLIDE_SDLTEXTURE_HPP_

#include <SDL2/SDL.h>

#include <cstdint>
#include <memory>
#include <string>

namespace xsecurelock_saver_slide {
class SdlRenderer;
class SdlSurface;

class SdlTexture {
 public:
  SdlTexture() = default;
  SdlTexture(SdlRenderer&, const std::string& file);
  SdlTexture(SdlRenderer&, SdlSurface&);

  struct Attributes {
    std::uint32_t format;
    int access;
    int width;
    int height;
  };

  Attributes QueryTexture();
  void SetTextureAlphaMod(std::uint8_t alpha);
  void SetTextureBlendMode(SDL_BlendMode);

  SDL_Texture* get() { return texture_.get(); }

 private:
  struct Deleter {
    void operator()(SDL_Texture*) const noexcept;
  };

  std::unique_ptr<SDL_Texture, Deleter> texture_{};
};
}  // namespace xsecurelock_saver_slide

#endif  // XSECURELOCK_SAVER_SLIDE_SDLTEXTURE_HPP_
