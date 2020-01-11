# Rootkits
This workshop focused on talk about kernel modules, starting with reviewing basics of operating systems and how to write and build a simple modules. In preparation to delve into building rootkits.

['nuf sqwaking! Gimmeh teh Codez!](#fine-fine-gimmeh-teh-codez)

## What are is Kernel?

## Backup, what is OS?

## Intuitions

## Kernel/Userspace

## What are Kernel Modules (LKM. L for Loadable)
Kernel modules are pieces of code that offer some functionality.   
They are "modules" (read: modular), in that each is usually self-contained and targetted towards a particular purpose.  

Loadable Kernel Modules are a feature of Linux (and some other OSs) where you can insert the piece of code while the Kernel is running, and similarly remove it. There is no need to shutdown, recompile the kernel, replace it and restart it. All this can be done in a "plug-and-play" fashion.

## Why do this?
One big use case is drivers for hardware.  
If you wanted a piece of hardware to work with an OS, you need a driver to expose this functionality.  
Being able to load and unload drivers (say for a network device, or a external proprietary usb device) is a pretty nice thing to have available.  
Or perhaps you rarely use a piece of hardware (say a Jazz Drive, for whatever reason), then you can load/unload the module for the duration of use and keep extraneous running code to a minimum.

## Great, but why should security club care? (esp about Jazz Drives)
Kernel is the main bastion of protection in an OS. 
Its whole purpose is to  
1) provide services to userspace apps  
2) prevent them from doing things that jeopardize other apps.  

By being able to inject code into the kernel directly, we can comprise #2 and get access to protected information that we wouldn't normally be able to get at.  
We would effectively be able to inspect and change memory, access hardware that usually be prevented, compromise security of apps, circumvent any protection, and more importantly obviate being able to be detected.   

Simpler terms, ultimate pwnage.

## Fine, fine. Gimmeh teh codez!

### First, setup a VM.  
__Don't do this on your machine, because you'll brick it__  
1. Install VirtualBox (https://www.virtualbox.org/)  
    VirtualBox is a hypervisor, that'll run a Linux Virtual Machine for you.

2. Install Vagrant (https://www.vagrantup.com/docs/installation/)  
    Vagrant is a front-end to control setup of VMs for many providers.  
    It's not necessary, but makes configuration and usage much easier.

3. Get a VM image.  
        Get the latest ubuntu VM (you can get what ever flavor, but Ubuntu is like the "hello-world" of linux)  

### Second, install reqs:

1. Kernel headers  
    These are the sources for the current kernel you are using.   
    ``sudo apt-get install build-essential linux-headers-`uname -r` ``
2. Build utils   
    ``sudo apt-get install libelf-dev``

### Clone this repo
``git clone https://github.com/aenygma/davis-cyber-sec-club ~``


## References:
1. All the code was copied from: https://blog.sourcerer.io/writing-a-simple-linux-kernel-module-d9dc3762c234
2. Designing BSD Rootkits is a great book. https://ihatefeds.com/No.Starch.Designing.BSD.Rootkits.An.Introduction.To.Kernel.Hacking.Apr.2007.ISBN.1593271425.pdf
