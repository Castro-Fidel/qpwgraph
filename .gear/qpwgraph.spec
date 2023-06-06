Name: qpwgraph
Version: 0.4.2
Release: alt1

Summary: PipeWire Graph Qt GUI Interface

License: GPLv2+
Group: Sound
Url: https://gitlab.freedesktop.org/rncbc/qpwgraph

# Source-git: https://gitlab.freedesktop.org/rncbc/qpwgraph.git
Source: %name-%version.tar

BuildRequires(pre): rpm-macros-cmake
BuildRequires: gcc-c++
BuildRequires: cmake
BuildRequires: qt6-svg-devel
BuildRequires: pkgconfig(libpipewire-0.3)
BuildRequires: pkgconfig(alsa)
BuildRequires: desktop-file-utils
BuildRequires: libappstream-glib

Requires: hicolor-icon-theme
Requires: shared-mime-info

%description
qpwgraph is a graph manager dedicated to PipeWire, using the Qt C++ framework,
based and pretty much like the same of QjackCtl.

%prep
%setup

%build
%cmake \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_BUILD_TYPE=RelWithDebInfo
%cmake_build

%install
%cmake_install

%files
%doc LICENSE.md
%doc README.md
%_bindir/%name
%_iconsdir/hicolor/*/*/*
%_desktopdir/org.rncbc.%name.desktop
%_datadir/mime/packages/org.rncbc.%name.xml
%_man1dir/%name.1.*
%_datadir/metainfo/org.rncbc.%name.metainfo.xml
%_datadir/mime/packages/org.rncbc.%name.xml

%changelog
* Tue Jun 06 2023 Mikhail Tergoev <fidel@altlinux.org> 0.4.2-alt1
- Initial build for Sisyphus

