Asset =
{
	Resource =
	{
		ResourceGroup = "media/model/dog",
		AssetPath = "media/model/dog",
		Mesh = "dog.mesh",
		Skeleton = "dog.skeleton",
		RigidBody = "dog.bullet",
	},
	AnimationTrack =
	{
		["idle"] = "idle.skeleton",
		["run"] = "run.skeleton",
		["walk"] = "walk.skeleton",
	},
	AudioTrack =
	{
		["idle"] = "idle.ogg",
		["run"] = "run.ogg",
		["walk"] = "walk.ogg",
	},
}
-- string(bullet_file)
-- vec3(x,y,z)
-- scalar(radius) scalar(height)
-- scalar(radius) scalar(height)
-- vec3(x,y,z)
-- scalar(radius)
-- vec3(x,y,z) scalar(planeConstant)
