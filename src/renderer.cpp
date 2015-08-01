#include "renderer.hpp"
#include "perspectivecamera.hpp"
#include "geometry.hpp"
#include "intersect_result.hpp"
#include "vector.hpp"
#include "material.hpp"
#include "color.hpp"

void Renderer::renderDepth(cil::CImg<unsigned char> &img, Geometry& scene, PerspectiveCamera& camera, double maxDepth){
    scene.init();
    camera.init();
    int i = 0;
    int w = img.width(), h = img.height();
    auto pixels = img.data();
    for (int y = 0; y < h; y++) {
        double sy = 1.0 - (double)y / h;
        for (int x = 0; x < w; x++) {
            double sx = (double)x / w;
            PtrRay ray = camera.generateRay(sx, sy);
            PtrIntersectResult result = scene.intersect(ray);
            if (result->getGeometry()) {
                int depth = 255.0 - std::min((result->getDistance() / maxDepth) * 255.0, 255.0);
                img.atXYZC(x, y, 0, 0) = depth;
                img.atXYZC(x, y, 0, 1) = depth;
                img.atXYZC(x, y, 0, 2) = depth;
                //atXYZC(x, y, 0, 0) = 255;
            }
            i += 4;
        }
    }
}
void Renderer::renderNormal(cil::CImg<unsigned char> &img, Geometry& scene, PerspectiveCamera& camera, double maxDepth){
    scene.init();
    camera.init();
    int i = 0;
    int w = img.width(), h = img.height();
    auto pixels = img.data();
    for (int y = 0; y < h; y++) {
        double sy = 1.0 - (double)y / h;
        for (int x = 0; x < w; x++) {
            double sx = (double)x / w;
            PtrRay ray = camera.generateRay(sx, sy);
            PtrIntersectResult result = scene.intersect(ray);
            if (result->getGeometry()) {
                PtrVector pNormal = result->getNormal();
                int depth = 255.0 - std::min((result->getDistance() / maxDepth) * 255.0, 255.0);
                img.atXYZC(x, y, 0, 0) = (pNormal->x() + 1) * 128;
                img.atXYZC(x, y, 0, 1) = (pNormal->y() + 1) * 128;
                img.atXYZC(x, y, 0, 2) = (pNormal->z() + 1) * 128;
                //atXYZC(x, y, 0, 0) = 255;
            }
            i += 4;
        }
    }
};

void Renderer::rayTrace(cil::CImg<unsigned char> &img, Geometry& scene, PerspectiveCamera& camera){
    scene.init();
    camera.init();
    int i = 0;
    int w = img.width(), h = img.height();
    auto pixels = img.data();
    for (int y = 0; y < h; y++) {
        double sy = 1.0 - (double)y / h;
        for (int x = 0; x < w; x++) {
            double sx = (double)x / w;
            PtrRay ray = camera.generateRay(sx, sy);
            PtrIntersectResult result = scene.intersect(ray);
            if (result->getGeometry()) {
                PtrMaterial pMaterial = result->getGeometry()->getMaterial();
                PtrColor color = pMaterial->sample(ray, result->getPosition(), result->getNormal());
                img.atXYZC(x, y, 0, 0) = std::min( int(color->r() * 255), 255);
                img.atXYZC(x, y, 0, 1) = std::min( int(color->g() * 255), 255);
                img.atXYZC(x, y, 0, 2) = std::min( int(color->b() * 255), 255);
            }
            i += 4;
        }
    }
}
