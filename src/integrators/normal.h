/*
    This file is part of TinyRender, an educative rendering system.

    Designed for ECSE 446/546 Realistic/Advanced Image Synthesis.
    Derek Nowrouzezahrai, McGill University.
*/

#pragma once

#include <core/platform.h>
#include <core/integrator.h>

TR_NAMESPACE_BEGIN

/**
 * Surface normal integrator.
 */
struct NormalIntegrator : Integrator {
    explicit NormalIntegrator(const Scene& scene) : Integrator(scene) { }

    v3f render(const Ray& ray, Sampler& sampler) const override {
        v3f color(0.f, 1.f, 0.f);
	// TODO: Implement this
		//std::cout << "Ray direction-> x: " << ray.d.x << " y: " << ray.d.y << " z: " << ray.d.z << std::endl;

		//IntersectionInfo* iInfo = new IntersectionInfo();
		SurfaceInteraction* hit = new SurfaceInteraction();
		if (scene.bvh->intersect(ray, *hit)/*bvh->getIntersection(ray, iInfo, false)*/) {
			v3f normal = hit->frameNs.n;
			color.x = abs(normal.x);
			color.y = abs(normal.y);
			color.z = abs(normal.z);
		}
		else {
			color.x = 0.f;
			color.y = 0.f;
			color.z = 0.f;
		}

		delete(hit);
        return color;
    }
};

TR_NAMESPACE_END