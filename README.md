# AIR 3 Windows-x86 Native Extension for Taskbar (Progress) API

AIR 3 Native Extension was written  in C++ to provide access to Windows 7 Taskbar API (Only Progress at moment).

### Requirements

+ [Microsoft C++ Redistributable Bundle 2010 x86](http://www.microsoft.com/download/en/details.aspx?id=5555);
+ [Adobe AIR 3.0 RC 1](http://labs.adobe.com/downloads/air3.html);
+ JRE and Apache Ant(Only for compile/package purposes).

### Example

A functional example can be downloaded at  `taskbar-progress-example/target/taskbar-progress-example.exe`.

![Example](http://dl.dropbox.com/u/473693/fre-taskbar-progress/img/example.png)

### For Devs

+ The C++ project, `fre-taskbar-progress`, can be imported in Microsoft Visual C++ 2010 Express Edition;
+ Remeber to change `FLEX_HOME` parameter at `build.properties` for the Flex projects (Library and Example) before running the  build scripts.