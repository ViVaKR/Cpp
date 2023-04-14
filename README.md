# CPP

## Run Demo Test

```bash
    ./run.sh
```

## [Ref Documnent Site](https://cplusplus.com/)

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

## C++ User Snippets

- File Location (macOS)
  - `~/Library/Application Support/Code/User/snippets/cpp.json`
- Short Cut (macOS)
  - `CMD + SHIFT + P` -> `Snippets: Confugur User Snippets`

- Examples
  - $0 : end, $1 : first, $2 : second..., prefix : snippet key word, body : result
  - `\n` : new line, `\t` : tab(4) indent

```json
{
    "Viv For Loop": {
        "prefix": "forv",
        "body": "for (int ${1:i} = ${2:0}; ${1:i} < ${3:10}; ${1:i}++) \n{\n\t${0}\n}",
        "description": "Cpp For Loop"
    },
    "Viv Nested For Loop": {
        "prefix": "forrv",
        "body": "for (int i = ${1:0}; i < ${2:10}; i++)\n{\n\tfor (int j = ${3:0}; j < ${4:10}; j++)\n\t{\n\t\t${0}\n\t}\n}",
        "description": "Cpp Nested For Loop"
    },
    "Viv std::cout": {
        "prefix": "outs",
        "body": [
            "std::cout << ${1:str} << ${2:var} << std::endl;$0"
        ],
        "description": "std::cout"
    },
    "Viv cout": {
        "prefix": "outc",
        "body": [
            "cout << ${1:str} << ${2:var} << endl;$0"
        ],
        "description": "without std, cout"
    },
    "Viv cout one": {
        "prefix": "out",
        "body": [
            "cout << ${1:str} << endl;$0"
        ],
        "description": "without std, cout"
    },
    "Viv cout no new line": {
        "prefix": "outno",
        "body": [
            "cout << \"${1:str}\";$0"
        ],
        "description": "without std, cout"
    },
    "Viv Add New Line": {
        "prefix": "blank",
        "body": [
            "std::cout << endl;${0}"
        ],
        "description": "Viv Add New Line"
    },
    "Viv std::cin": {
        "prefix": "in",
        "body": [
            "std::cin >> ${1:var};$0"
        ],
        "description": "Viv std::scin"
    },
    "Viv if return": {
        "prefix": "ifr",
        "body": [
            "if (${1:condition}) return;${0}"
        ],
        "description": "if condition return"
    },
    "Viv include <iostream>": {
        "prefix": "#v",
        "body": [
            "#include <iostream>\n\nusing namespace std;${0}"
        ],
        "description": "Viv include <iostream>"
    },
    "Viv Make Function": {
        "prefix": "vfunc",
        "body": [
            "void ${1:Demo}(${2:int} ${3:args}) {",
            "\t${4:cout << \"Hello World\";$0}",
            "}"
        ],
        "description": "Viv Make void type function"
    }
}
// ~/Library/Application Support/Code/User/snippets/cpp.json

```

---

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

### 2. C++ Library `.dylib` Copy to `CSharp Project Resources/Libs/demo.dylib`

### 3. (CSharp) C++ Library `.dylib` : CSharp Import Exampe

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

- Variable
  - Local = declared inside a function or block {}
  - Globla = declared outside of all functions

### cmake reinstall

```bash
    brew install --formula cmake
    brew link --overwrite cmake
```

---

### Memory Address : A location in memory where data is stored

> A memory address can accessed with `&` (address-of operator)  

## [Ref : Bro Code C++](https://youtu.be/-TkoO8Z07hI)
