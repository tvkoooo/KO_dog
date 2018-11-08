在blender中,按p运行,然后导出bullet格式


http://blog.toonormal.com/2011/10/06/notes-exporting-bullet-data-from-blender-2-5/


Notes: Exporting .bullet data from Blender 2.5
Here’s some notes from my internal wiki.

How to export .bullet data from a Blender 2.5x scene (awfully close to 2.6 now ‘eh). This might be as of Blender 2.57, and should continue to work well in to 2.6x.

Exporting Bullet Data from Blender
Exporting Bullet Physics data from Blender is a pain in the ass. Plain and Simple. It *SHOULD* be a right click export, but no, it’s complicated.

1. Switch to Game Engine Mode (In the Title Bar, the default setting is “Blender Render”. Should be “Blender Game”).
2. Game Engine Mode changes the *Physics* Properties (bouncing ball)
* Make the Physics Type a “Rigid Body”
* Enable Collision Bounds, and pick a bounding volume type (boxes, hulls)
* To make compound objects, you need to treat one object as the parent, and check the compound buttons
* Under the *Object* Properties (tiny cube), Relations Parent can be used to identify oneself as a child of a parent
* Defining compound objects is required to make overlapping volumes that don’t affect each-other.
3. Change a pane to a *Logic Editor* (little red-ball joystick)
4. Add a “Keyboard” sensor, and set the key to the spacebar (for example… we’re binding the spacebar to an action)
5. Add a “Python” controller
6. Change a pane to a *Text Editor*
7. Hit + to create an instance (default name is “text”)
8. Paste the following script in to the text editor


import bpy;
import PhysicsConstraints;
print( "Exporting..." );
PhysicsConstraints.exportBulletFile( bpy.path.ensure_ext(bpy.data.filepath,".bullet") );
1
2
3
4
import bpy;
import PhysicsConstraints;
print( "Exporting..." );
PhysicsConstraints.exportBulletFile( bpy.path.ensure_ext(bpy.data.filepath,".bullet") );
9. Update the “Python” controller to use this script file
10. Drag a link between the Keyboard sensor and the python controller (see the little nodes between them)
11. If you haven’t already, save the .blend file. If you close Blender, then double click on the saved .blend file, it will change the current working directory of Blender. This is important, because the script above (with no path) saves the .bullet file to the working directory.
12. Finally, to generate the blend file, run the simulation (R key).
13. To export, while the simulation is running, push the spacebar.
14. The console will show the “Exporting…” message. If you don’t have a blender console, you can enable it under Help->Toggle Blender Console

Done. That’s the annoying way to export .bullet data from blender.

The reason for the complicated procedure is that the PhysicsConstraints and bge libraries are just not available in standard plugin scope. Right clicking and running the script, just not an option. So we need to enter a game instance, where all these helpful library instances exist (as otherwise you wouldn’t have physics).

Research conducted on October 6th, 2011, using Blender 2.59.

References
http://www.blender.org/documentation/blender_python_api_2_59_3/bpy.path.html

http://bulletphysics.org/Bullet/phpBB3/viewtopic.php?f=9&t=6683&p=23315#p23315

http://wiki.blender.org/index.php/Doc:2.5/Manual

This entry was posted on Thursday, October 6th, 2011 at 12:48 PM	and is filed under Alone, The, Technobabble. You can follow any responses to this entry through the RSS 2.0 feed. Both comments and pings are currently closed.







http://xissburg.com/post/export-bullet-from-blender/


How to export .bullet files from Blender
To export .bullet files from Blender you have to use the Blender Game Engine. First you have to setup the physical properties of each object, then create a little Python script which is invoked by a keyboard action you create in the Logic Editor. Then you run the game engine and press that key to run the script which exports the file. Let’s go over this process step by step.

After creating your objects move over to the Properties Editor, Physics tab. Make sure you select Blender Game as the renderer or the Physics tab won’t be visible.


Usually you want to set the Physics Type to either Static or Rigid Body. If it’s a rigid body then you should also set the Mass. Then you should check the Collision Bounds box and select the type of collision shape you want. If you select either one of Capsule, Box, Cylinder, Cone and Sphere, you might notice the shape does not align with your object. That’s because the center of the shape is set to the center of the object in Blender, then to fix it you should change the origin of your object so the physics shape will fit the way you want. Also note that Triangle Mesh is only valid for static objects (it outputs a btScaledBvhTriangleMeshShape).

Once your objects have their physical properties set, you’re ready to export. Then open the Text Editor…