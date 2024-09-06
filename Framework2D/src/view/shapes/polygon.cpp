#include "view/shapes/polygon.h"

#include <imgui.h>

namespace USTC_CG
{
void Polygon::draw(const Config& config) const
{
    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    for (int i = 0; i < this->points.size(); i++)
    {
        if (i == this->points.size() - 1)
        {
            if (preview_point != nullptr)
            {
                draw_list->AddLine(
                    ImVec2(
                        config.bias[0] + points[i].x,
                        config.bias[1] + points[i].y),
                    ImVec2(
                        config.bias[0] + preview_point->x,
                        config.bias[1] + preview_point->y),
                    IM_COL32(
                        config.line_color[0],
                        config.line_color[1],
                        config.line_color[2],
                        config.line_color[3]),
                    config.line_thickness);
            }    
        }
        else
        {
            draw_list->AddLine(
                ImVec2(
                    config.bias[0] + points[i].x, config.bias[1] + points[i].y),
                ImVec2(
                    config.bias[0] + points[i + 1].x,
                    config.bias[1] + points[i + 1].y),
                IM_COL32(
                    config.line_color[0],
                    config.line_color[1],
                    config.line_color[2],
                    config.line_color[3]),
                config.line_thickness);
        }
        }
}

void Polygon::update(float x, float y)
{
    this->points.push_back(ImVec2(x, y));
}

void Polygon::preview(float x, float y)
{
    this->preview_point = std::make_unique<ImVec2>(x, y);
}

void Polygon::confirm()
{
    this->preview_point.reset();
}
}