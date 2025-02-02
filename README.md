# splitOS installer image builder
> Perl script to create splitOS installer images  

![Current Version Badge](https://img.shields.io/badge/current_version-v0.1.0-blue)

## Dependencies
- cURL or wget (for downloading GNU coreutils for the userspace in the initramfs)
    - Debian, Fedora, & Nixpkgs: `curl` / `wget`
    - Arch: `core/curl` / `extra/wget`
    - Gentoo: `net-misc/curl` / `net-misc/wget`
- Git (for cloning Limine's source code for compiling)
    - Debian, Fedora & Nixpkgs: `git`
    - Arch: `extra/git`
    - Gentoo: `dev-vcs/git`

## Roadmap

### Planned soon
- Command-line arguments
- Dynamic current version badge
- Downloading pre-compiled kernel image or specifying alternate path if local image not found
- Confirmation to delete conflicting files when creating the work or cache dirs
- Have a list of extra packages that will be included in the live system