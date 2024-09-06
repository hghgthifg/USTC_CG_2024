#include "view/shapes/ellipse.h"

#include <imgui.h>

namespace USTC_CG
{
void Ellipse::draw(const Config& config) const
{
    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    ImVec2 center = ImVec2(
        (start_point_x_ + end_point_x_) / 2.0f + config.bias[0],
        (start_point_y_ + end_point_y_) / 2.0f + config.bias[1]
    );

    draw_list->AddEllipse(
        center, 
        (end_point_x_ - start_point_x_) / 2.0f,
        (end_point_y_ - start_point_y_) / 2.0f,
        IM_COL32(
            config.line_color[0],
            config.line_color[1],
            config.line_color[2],
            config.line_color[3]),
        0, 0, config.line_thickness
    );
}

void Ellipse::update(float x, float y)
{
    end_point_x_ = x;
    end_point_y_ = y;
}
}