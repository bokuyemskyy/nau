# blackhole
A real-time GLSL renderer that visualizes a non-rotating black hole, gravitationally warped sky and a glowing accretion disk. This project is a small dive into the physics of black holes, built using real space-warping formulas rather than purely simulating visual effects. I derived the geodesic equations for a Schwarzschild black hole and implemented a simple RK4 integrator to trace light rays.

While the underlying ray-tracing is based on actual physics, this is not a physically rigor simulation: the RK4 integrator introduces approximation errors, and the accretion disk emission is entirely artistic rather than physically accurate. 

<img width="1659" height="997" alt="Screenshot 2026-02-28 at 19 40 20" src="https://github.com/user-attachments/assets/94f78016-4f80-4dae-b06f-5cec7c0f8820" />
