# Starter Grid (Snap) System for Unreal Engine >=5.1

The goal of this project is to provide a simple starting point to build a performant grid system to snap actors to a landscape. Most examples found on the web use a fleet of meshes to trace the location which causes huge performance drops when expanding the grid to fit a large landscape.
This project provides the functionality to calculate the current snap location which simulates an infinite grid. This means you can use the grid on any landscape without worrying about size or performance.

The provided example uses the Third Person Character template.

# Source Code

- [GridSystem.h](Source\GridSystemExample\GridSystem\GridSystem.h)
- [GridSystem.cpp](Source\GridSystemExample\GridSystem\GridSystem.cpp)
- [SnapAxis.h](Source\GridSystemExample\GridSystem\SnapAxis.h)
