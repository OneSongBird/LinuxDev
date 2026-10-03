Name:           Show
Version:        0.0.1
Release:        alt1
Group:          Other
License:        MIT
URL:            https://uneex.org/LecturesCMC/LinuxApplicationDevelopment2026/03_Packaging
Source:         %name-%version.tar.gz
Summary:        Package Show

%description
Package Show
Done for LecturesCMC/LinuxApplicationDevelopment2026/03_Packaging.

%prep
%setup

%build
make

%install
install -D %name %buildroot%_bindir/%name

%files
%_bindir/%name