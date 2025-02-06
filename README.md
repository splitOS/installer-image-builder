# splitOS installer image builder
> Perl script to create splitOS installer images  

![Current Version Badge](https://img.shields.io/badge/current_version-v0.1.0-blue)

## Dependencies
- Git (for cloning GNU coreutils and Limine source code)
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