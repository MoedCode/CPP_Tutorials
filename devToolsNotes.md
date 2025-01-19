The discrepancy in GCC versions between your **Windows** and **WSL** environments is due to the different package managers and repositories used in each system. Here's a detailed explanation:

---

### 1. **Windows (MSYS2)**:
   - On Windows, you are using **MSYS2**, which provides a rolling-release environment for software packages.
   - MSYS2 frequently updates its packages, including GCC, to the latest versions available.
   - As of October 2023, MSYS2 provides **GCC 14.2.0**, which is a pre-release or development version of GCC.
   - MSYS2 is not tied to the release cycle of any specific Linux distribution, so it can offer newer versions of software.

---

### 2. **WSL (Ubuntu 20.04)**:
   - On WSL, you are using **Ubuntu 20.04**, which is a Long-Term Support (LTS) release.
   - LTS releases prioritize stability over having the latest software versions.
   - The default repositories for Ubuntu 20.04 provide **GCC 13.1.0**, which is the latest stable version available in its repositories.
   - Even though GCC 14 might be available upstream, it is not included in the default repositories for Ubuntu 20.04 because it is not yet considered stable or fully tested for this LTS release.

---

### Why the Difference?

- **Package Management**:
  - MSYS2 on Windows uses its own package manager (`pacman`) and repositories, which are independent of Linux distributions.
  - WSL uses the package manager (`apt`) and repositories of the installed Linux distribution (e.g., Ubuntu).

- **Release Cycle**:
  - MSYS2 follows a rolling-release model, meaning it provides the latest versions of software as soon as they are available.
  - Ubuntu LTS releases (like 20.04) prioritize stability and only include software versions that have been thoroughly tested.

- **GCC Version Availability**:
  - GCC 14 is a pre-release or development version and is not yet included in the stable repositories of Ubuntu 20.04.
  - MSYS2, being a rolling-release environment, includes GCC 14 as it becomes available.

---

### How to Get GCC 14 on WSL (Ubuntu 20.04)

If you want to use GCC 14 on WSL, you have a few options:

#### Option 1: Upgrade to a Newer Ubuntu Version
   - Upgrade your WSL distribution to a newer version of Ubuntu (e.g., Ubuntu 22.04 or 23.10), which may include newer versions of GCC.
   - To upgrade:
     ```bash
     sudo do-release-upgrade
     ```

#### Option 2: Use a Third-Party PPA
   - You can add a third-party PPA (Personal Package Archive) that provides newer versions of GCC.
   - For example, the `ubuntu-toolchain-r` PPA often includes newer GCC versions:
     ```bash
     sudo add-apt-repository ppa:ubuntu-toolchain-r/test
     sudo apt update
     sudo apt install gcc-14 g++-14
     ```

#### Option 3: Build GCC from Source
   - If you need the absolute latest version of GCC, you can download and build it from source. This is more complex and time-consuming but gives you full control over the version.

---

### Summary

- **Windows (MSYS2)**: Provides GCC 14.2.0 because it follows a rolling-release model and includes the latest software versions.
- **WSL (Ubuntu 20.04)**: Provides GCC 13.1.0 because it is an LTS release that prioritizes stability over having the latest software.

To get GCC 14 on WSL, you can either upgrade your Ubuntu distribution, use a third-party PPA, or build GCC from source.

Let me know if you need further assistance!