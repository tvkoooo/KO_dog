blender2ogre �Ƽ�ʹ��blender2ogre�����ת��

blender ���û�����������·��
����Ǵ��ϰ汾���������Ļ���Ҫ������Ŀ¼�е��ļ�ɾ��
```
	blender2ogre.pickle
	io_ogre.pickle
```
һ��������Ŀ¼
C:\Users\<UserName>\AppData\Roaming\Blender Foundation\Blender\2.70\config\scripts
%USERPROFILE%\AppData\Roaming\Blender Foundation\Blender\2.79\

�� blender2ogre/io_ogre ���������blender�����еĲ��Ŀ¼blender-2.70a-windows64\2.70\scripts\addons

������ѡfile->User Preferences > Add-Ons > Import-Export
�ҵ�io_ogre ��OGRE Exporter �ں���򹳼���������,Ȼ���Save User Setting

����ģ�ͺͳ�����Ҫ����ʱ
��file->export->OGRE Exporter

blender������õ�������,Ȼ��㵼��


i want export the file like Torchlight.one mesh one main skeleton,and some animation skeleton.what the export process?

i find the way to export Torchlight file struct.
1.new infantry_001.blend.add a cube and armature,select armature change mode to poss mode.select armature shift select cube ctrl+p add parent relationship,
here i use automatic weights.important:at object mode select armature ctrl+a apply location rotation scale ,same at cube .at object select cube and armature ctrl+g.rename the group name for "group_cube".select cube export dir "main",Cube.mesh and Cube.skeleton contain none animation.
2.new bend_l.blend.clear scene,ctrl+alt+o or file->link.select infantry_001.blend->Group->group_cube,we see this cube at scene but can not use poss.select the cube ctrl+alt+p choose armature to create a proxy,so can use poss mode.create one action at dope sheet use action edit mode.add key frame use i create one action name "bend_l".change to NLA edit add NlaTrack and use bend_l create one NlaStrip.select cube export.will export to dir "bend_l",Cube.mesh and Cube.skeleton contain animation name "bend_l".
3.repeat step create bend_r.blend and export to dir "bend_r",Cube.mesh and Cube.skeleton contain animation name "bend_r".
4.
copy main/Cube.mesh to finally/Cube.mesh
copy bend_l/Cube.skeleton to finally/bend_l.skeleton
copy bend_r/Cube.skeleton to finally/bend_r.skeleton

terrible export process,but useful.
