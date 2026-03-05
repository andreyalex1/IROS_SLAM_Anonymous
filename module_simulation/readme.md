# platform_simulation

## Structure

platform_simulation is a package that provide a simulation for System robot. For now it constist from several main modules:

- Launch group.
- Description group.

## Launch group

Launch group is a several folders inside a package. Main goal of this group is create simulation instance and start navigation on robot instance inside simulation. Group include:

- ```config``` - folder that holds a full config description for nodes used for creating simulation (like gazebo node) and for creating navigation (like rtabmap node)
- ```launch``` - folder that holds all launch files for creating simulation and navigation.

### Description group

Description group is a several folders inside a package. Main goal of this group is provide data files to instances that create simulation. Group include:

- ```description``` - folder that holds a full description to robot that used inside simulation in ```.urdf.xacro``` format.
- ```meshes``` - folder that contains texture for models that store inside ```description``` folder.
- ```models``` - folder that contains model for object that created inside simulation (like arrow, rocks and etc.).
- ```rviz``` - folder that contains description for ```rviz``` instance. That description setup ```rviz``` and makes all the necessary settings for you. 
- ```worlds``` - folder that contains description in format ```.world``` for several world used inside simulation (like mars word or moon world). 
