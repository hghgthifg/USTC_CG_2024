#pragma once

#include <vector>
#include <memory>
#include "imgui.h"
#include "shape.h"

namespace USTC_CG
{
class Polygon : public Shape
{
   public:
    Polygon() = default;

    Polygon(std::vector<ImVec2> point_list) : points(point_list)
    {
    }

    virtual ~Polygon() = default;

    void draw(const Config& config) const override;

    void update(float x, float y) override;

    void preview(float x, float y);

    void confirm();

   private:
    std::vector<ImVec2> points;
    std::unique_ptr<ImVec2> preview_point;
};
}