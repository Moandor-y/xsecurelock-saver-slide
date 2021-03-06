#ifndef XSECURELOCK_SAVER_SLIDE_IMAGE_VIEW_HPP_
#define XSECURELOCK_SAVER_SLIDE_IMAGE_VIEW_HPP_

#include "SdlSurface.hpp"
#include "SdlTexture.hpp"
#include "View.hpp"

namespace xsecurelock_saver_slide {
class SdlRenderer;

class ImageView : public View {
 public:
  ImageView(SdlRenderer&, SdlSurface&);
  using View::View;
  void SetImage(SdlSurface&);

  [[nodiscard]] int surface_width() const { return surface_width_; }
  [[nodiscard]] int surface_height() const { return surface_height_; }

 protected:
  void OnDraw() override;
  void OnPreDraw() override;

 private:
  SdlTexture texture_;
  double texture_alpha_ = 1;
  int surface_width_{};
  int surface_height_{};
};
}  // namespace xsecurelock_saver_slide

#endif  // XSECURELOCK_SAVER_SLIDE_IMAGE_VIEW_HPP_
