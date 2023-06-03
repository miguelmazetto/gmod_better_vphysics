# gmod_better_vphysics
Garry's Mod original physics engine with performance improvements. (WIP)
The dll/so is mostly functional and stable.

Clone with:
```console
git clone --recurse-submodules https://github.com/miguelmazetto/gmod_better_vphysics```

### Compile on Windows
```console
premake5 vs2022 ```
And open the visual studio .sln

### Compile on Linux
```console
premake5 gmake2```

For 32 bits:
```console
make -j```

For 64 bits:
```console
make -j config=debug_x86_64```

### Testing on Windows
Make a Garrys mod server in a folder called `testserver` at the root of the repo.
The Visual Studio solution generated already has a valid testing environment, just run it.

OBS: Testing on Linux is WIP (likely wont fix).