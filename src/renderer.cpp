#include "renderer.hpp"
#include "perspectivecamera.hpp"
#include "geometry.hpp"
#include "intersect_result.hpp"

void Renderer::renderDepth(cil::CImg<unsigned char> &img, Geometry& scene, PerspectiveCamera& camera, double maxDepth){
    scene.init();
    camera.init();
    int i = 0;
    int w = img.width(), h = img.height();
    printf("w = %d,h = %d\n", w,h);
    auto pixels = img.data();
    for (int y = 0; y < h; y++) {
        double sy = 1.0 - (double)y / h;
        for (int x = 0; x < w; x++) {
            double sx = (double)x / w;
            printf("sx=%f,sy=%f\n",sx,sy);
            PtrRay ray = camera.generateRay(sx, sy);
            PtrIntersectResult result = scene.intersect(ray);
            if (result->getGeometry()) {
                int depth = 255.0 - std::min((result->getDistance() / maxDepth) * 255.0, 255.0);
                printf("%d,%d,%d\n", x,y,depth);
                img.atXYZC(x, y, 0, 0) = depth;
                img.atXYZC(x, y, 0, 1) = depth;
                img.atXYZC(x, y, 0, 2) = depth;
                //atXYZC(x, y, 0, 0) = 255;
            }
            i += 4;
        }
    }
}
