# Burning-Flame2.0
# Adreno-Burning-Flame Demo


Basic Information:


Maintainer: Kou Zhiwu、YongRong、YanShiqin、FangBo、ZhangXu.

SDK tools:Qualcomm Adreno GPU SDK

Start date: August 23th, 2019.


Function description:

Develop a demonstration application to display a variable-color flame model using Adreno GPU SDK.



Document introduction:

===>Assets
    |
    |--Fonts:
         |--Tuffy12.pak:       Font pak resource file.
    |--Textures：
         |--Logo.pak:          Texture pak resource file.


===>Android
    |
    |--InstallAssets.bat:      Copy assets resource files.
    |--InstallAssets.sh：      Copy assets resource files.
    |--AndroidManifest.xml：   AndroidManifest file.
    |--jni：
         |--Android.mk:        Android make file.
         |--Application.mk:    Application make file.


===>glm:   OpenGL Mathematics(GLM) is a header only C++ mathematics library for graphics software based on the OpenGL Shading Language (GLSL) specifications.

===>particles.cpp:   Flame particles source code cpp file.

===>particles.h:   Flame particles source code header file.

===>Scene.cpp:   Main scene cpp file.

===>Scene.h:   Main scene header file.



Usage Instructions:

1、Download code from github according to the repository from　“https://github.com/ThunderSoft-XA/Burning-Flame2.0.git”.

2、Install Adreno GPU SDK v5.0.

3、Install Android NDK r17b.

4、Install Apache Ant 1.9.14.

5、Install Snapdragon Profiler.

6、Compile APK source code and install it to android device.

7、Open the APK, and you will enjoy it.

8、If you care about some performance indicators, you can use Snapdragon Profiler to view it.

