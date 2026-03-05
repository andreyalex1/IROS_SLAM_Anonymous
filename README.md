# OPEN LIBRARIES FOR AUTONOMOUS NAVIGATION OF A SIX-WHEELED MARS ROVER PROTOTYPE ON MODERATELY UNEVEN UNFAMILIAR TERRAIN WITH VISUAL RECOGNITION OF NAVIGATION TARGETS

## Open library for autonomous navigation by recognized movement indicators. (ResearchProject-SLAM)

"Open library for autonomous navigation by recognized movement indicators" developed under the program **"an open-source initiative"** and designed for automatic determination of rover current position (2D localization), for real-time terrain mapping (mapping), for building rover route considering terrain relief and ability to work without using global satellite positioning systems (navigation), as well as for rover movement control using algorithms SLAM (Simultaneous Localization and Mapping) in real conditions on moderately uneven terrain.

## Licensing (License)

This software is distributed under dual licensing: (This software is dual-licensed):

- MIT License (see [LICENSE]([Anonymous Repository]))
- Russian Open License (see [GENERAL_LICENSE-RF.md]([Anonymous Repository]))

You may use this project under the terms of either license (You may use this project under the terms of either license).

##

The library can be used on autonomous mobile platforms on land and in space for geological and ecological exploration, study and development of hard-to-reach areas, and monitoring energy equipment condition (including at nuclear power plants) without removing it from operation in poor communication conditions and lack of current maps.

The library is applicable only to 4- or 6-wheeled vehicles (rovers) with 4 steerable and all driving wheels. This vehicle must use Ackermann steering geometry.

The library must be compatible with cameras (including depth camera) and sensors installed on the rover controlling its movement and must work taking into account their readings.

For automated terrain map building during rover movement the library uses only Intel RealSense D435i depth camera. Remote sensing technologies (Lidars) are not used in this project.

Motion control sensors used are magnetic incremental encoders and inertial measurement unit WitMotion wt901. Magnetic incremental encoders are installed on the shafts of the rover drive motors. Their resolution, taking into account the reducers, 34*100 "clicks" per wheel revolution. Encoder calibration was performed experimentally, for this, an adjustable coefficient is provided in the "low-level rover motion control" module.

In addition to working with specific cameras and sensors, the code takes into account the following **rover dimensions:**
*   rover length 1,2+0,2m;
*   rover width 1,2+0,2m;
*   rover height with mast and communication antennas 1,3+0,3m;
*   tire diameter 295mm;
*   ground clearance 290мм.

**Platform:** 
*   ROS2 Humble (Robot Operating System 2 Humble version).

**Dependencies:** 
*   robot_localization,
*   Nav2,
*   Rtabmap,
*   BehaviorTree.CPP,
*   BehaviorTree.ROS2,
*   ROS2 (robot integration).

<a id="minsystemrequirements"></a>
**Minimum system requirements:**
*  Operating system: Ubuntu 22.04,
*  Processor: AMD Ryzen R7 6800U,
*  RAM: 16GB,
*  Disk space: 16 GB,
*  Presence of depth camera,
*  Presence of IMU WITMOTION WT901BLECL BLE5.0,
*  Presence of wheeled base with encoders on motors.

## Library packages

**For autonomous navigation simulation:** 
*   `platform_simulation` - complete package for simulating autonomous navigation of a six-wheeled rover in the "Gazebo" simulator.

**For real rover autonomous navigation:** 
*   `platform_localization` - rover localization package. 
*   `platform_navigation` - behavior tree package for map building and route planning.
*   `platform_bt` - rover autonomous navigation behavior tree package.
*   `platform_odometry` - package designed for odometry calculation based on encoder information.
*   `platform_controllers` - high-level rover motion controller package with Ackermann steering geometry. 
*   `platform_nav_lib` - main rover autonomous navigation package to a specified point or by recognized indicators, which uses the method of simultaneous localization, mapping, route planning and movement.

## 📖 Documentation

Complete technical documentation is available in the [docs/](./docs/):

*   [📄 Application Description](./docs/Описание%20применения-SLAM-merged.pdf) — description of application.
*   [📄 Programmer Guide](./docs/Руководство%20программиста-SLAM-merged.pdf) — library programmer guide `platform_nav_lib`.

---

The operation of the "Open library for autonomous navigation by recognized movement indicators" is guaranteed when running on platforms with hardware CPU at rover movement speeds not exceeding 5 km/h. However, the rover must be equipped with a second hardware platform with GPU hardware, on which the movement indicator recognition module runs.

Testing of this library was performed on the platform "Mini PC Beelink SER5 Max (AMD Ryzen 5 5500U)". As a second platform, Nvidia Jetson Orin NX Super was used to run the movement indicator recognition module. On the [system](https://[Anonymous Repository]) both hardware platforms are combined into a single hardware stack managed by ROS2 Humble (Robot Operating System 2 Humble version).

