# CPP

## 컴파일러 (Compiler)

- [Windows Download - GCC MinGW-w64 compiler for Windows](https://winlibs.com/)

1. Mingw : Windows - VSCode
2. Msvc : Windows - Microsoft Visual Studio
3. Clang : MacOS
4. Gcc : Linux

---

## 종합 코드 편집기 (IDE)

1. Visual Studio Code
2. Micorsoft Visual Studio
3. CodeLite
4. QT Create
5. XCode : MacOS

## Visual Studio Code Settings : Target: x86_64-apple-darwin19.6.0

### `launch.json`

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Viv C++",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/${fileBasenameNoExtension}",
            "args": [],
            "stopAtEntry": true,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "lldb",
            "preLaunchTask": "Build Viv GCC"
        }
    ]
}
```

```json
{
 "version": "2.0.0",
    "runner": "terminal",
    "echoCommand": true,
    "presentation": {
        "echo": true,
        "reveal": "always",
        "focus": false,
        "panel": "shared",
        "showReuseMessage": false,
        "clear": false
    },
 "tasks": [
        {
            "type": "cppbuild",
            "label": "Build Viv GCC",
            "command": "/usr/local/bin/g++-12",
            "args": [
                "-g",
                "-std=c++23",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "compiler: /usr/local/bin/g++-12"
        }
    ]
}
```

### tasks.json example (compiler : c++-12 and clang++ 12.0.0)

```json
{
 "version": "2.0.0",
 "tasks": [
        {
            "type": "cppbuild",
            "label": "Build Viv GCC 12.2.0",
            "command": "/usr/local/bin/g++-12",
            "args": [
                "-g",
                "-std=c++23",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "compiler: /usr/local/bin/g++-12"
        }
    ]
}

```

---

## C++ Library Export And Import CSharp Project

### 1. (C++) Make C++ Library `.dylib`  (ex) demo.dylib

```bash
    # compiler `g++-12` 
    g++-12 -shared -o demo.dylib demo.cpp
```

## 2. C++ Library `.dylib` Copy to `CSharp Project Resources/Libs/demo.dylib`

## 3. (CSharp) C++ Library `.dylib` : CSharp Import Exampe

```xml
    <ItemGroup>
        <Content Include="Resources/Libs/demo.dylib">
            <CopyToOutputDirectory>Always</CopyToOutputDirectory>
        </Content>
    </ItemGroup>

```

```csharp

    [DllImport("Resources/Libs/demo.dylib")]
    public static extern int demo(int arg1, string arg2);
    static void Main(string[] args)
    {
        Console.WriteLine($"Hello, World! {demo(12, "Hello World")}");
    }

```

---
