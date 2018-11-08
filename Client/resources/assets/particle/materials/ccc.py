# iCCP: known incorrect sRGB profile 15:54:22

import os
# magick.exe
commandTool = 'magick.exe'
# rootPath
def FindExamAllFiles(_rootPath):
    _pngFiles = []
    for root, dirs, files in os.walk(_rootPath):
        for filepath in files:
            imgFileFullPath = os.path.join(root, filepath)
            if imgFileFullPath.endswith('.png'):
                _pngFiles.append(imgFileFullPath)
    return _pngFiles

def doStripPath(_path):
    pngPathList = FindExamAllFiles(_path)
    print ("command=%s" % _path)
    for pngPath in pngPathList:
        print ("command=2")
        # 
        command = "{0} \"{1}\" \"{2}\"".format(commandTool, pngPath, pngPath)
        os.system(command)	
        print ("command=%s" % command)
		
def doStrip():
    doStripPath(r"textures")

if __name__ == "__main__":
    doStrip()	
    print ("command=")
		