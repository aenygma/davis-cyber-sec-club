# Rootkits
This workshop focused on talk about kernel modules, starting with reviewing basics of operating systems and how to write and build a simple modules. In preparation to delve into building rootkits.

['nuf sqwaking! Gimmeh teh Codez!](#fine-fine-gimmeh-teh-codez)

## What is Kernel?
Kernel is an abstraction.  
It's a program (or set of running procedures) that provides uniform and protected access to set of hardware.  
It is fundamental in providing a platform for userspace applications to run on.

## Backup, what is an OS?
Operating System. Next question!

## Backup further
One day some loser cobbled together some parts and made a machine. It did a thing. And only 1 thing.  
Then of course, other nerds wanting bragging rights, made their own. Though everyone put their own spin on how the computer worked.  
The problem was that you can bunch of hardware, that was doing something simliar, but no way of having them do the same computation, cuz everyone had their own homebrewed thing.  
Someone marginally smart said, "Hey, let's have some code that all machines can run, so people that use that code can write things consistently, and you know, not repeat same code and maybe even share things."
If this seems like a Platform or an API, it effectively is.

The advantage of this was that the programmer didn't have to know the hardware idiosyncracies of each crazy set of cobbled together mess. Simply that they get a small menu of functions they can use, the rest is taken care of by someone else (read: abstraction).

--- 
An Operating System is such a thing.  

You, as a programmer, don't have to worry or even think about booting a machine, initializing the hardware, loading the right drivers, managing memory (or any storage), how to display thing to screen, managing resource, coordinating activities, etc.  
All of this "basic" functionality is handled for you by the OS. So you can leverage what it provides to do what you want to.   

It is fundamentally an abstraction.  

## Intuitions
It is my opinion that you should use real-life metaphors for understanding this, if at least because that's how these were drawn from.  

### Restaurant:
__Think of a restaurant as a service, there are many abstractions embedded in there.__

1. You, the patron, are hungry. So you go to a sit down restaurant.
2. Immediately, the host/hostess/maitre d' will receive and seat you. If not, you are enqueued.
3. When you do get to sit down, you choose from a menu, and request it the waiter/waitress.
4. They translate your request, submit the order to the kitchen.
5. [ lot of things happen in kitchen ]
6. You get your meal, eat, hopefully pay and leave.

#### Note:
* You __do not__ get to go into the kitchen to make your own meal.
* You __do not__ get to do whatever you want in the restaurant, or you'll be kicked out.
* You __do not__ have full control over all the things.
* In exchange for convienience of the service, you get a limited, but consistent set of options.
* You are not the only patron in the restaurant.
---

The restaurant here is taking care of how to 
#### Allocate resources: 
1. Whether they can seat you, if not queue.
2. Making sure you get time to submit your order to waitstaff.
3. Making sure your order gets enough time with cooking staff.

#### Ensure Isolation:  
4. Making sure other patron's activity doesn't impact yours uniquely.
5. Making sure your order is not impacted by others.
6. Making sure your experience is good; ie hotel is functional. (No leaks, electricity/plumbing works, etc)

#### Coordination:  
7. Making sure all the activities are coordinated properly. A restaurant needs janitors, accounting, cooks, managers, finances, real estate owners, utility services.  
It needs to ensure that all of these work in concert and not impact one another.
8. Making sure to prioritizing resources for right jobs properly. A leaky ceiling should be addressed quickly, and comes at the expense of trivial things.
9. Being able to handle (some amount of) failures as they happen, as still be functional.

__NOTE__: these divisions are mine, but they can be divided in different ways. One common one is _Illusionist_, _Referee_, and _Glue_. 

### Government:
[TODO: Expand this.]

## Kernel/Userspace
Kernel is the protected space that users don't have access to.  
Userspace is where applications typically run.  
[TODO: Expand this more.]

## What are Kernel Modules (LKM. L for Loadable)
Kernel modules are pieces of code that offer some functionality.   
They are "modules" (read: modular), in that each is usually self-contained and targetted towards a particular purpose.  

Loadable Kernel Modules are a feature of Linux (and some other OSs) where you can insert the piece of code while the Kernel is running, and similarly remove it. There is no need to shutdown, recompile the kernel, replace it and restart it. All this can be done in a "plug-and-play" fashion.

## Why do this?
One big use case is drivers for hardware.  
If you wanted a piece of hardware to work with an OS, you need a driver to expose this functionality.  
Being able to load and unload drivers (say for a network device, or a external proprietary usb device) is a pretty nice thing to have available.  
Or perhaps you rarely use a piece of hardware (say a Jazz Drive, for whatever reason), then you can load/unload the module for the duration of use and keep extraneous running code to a minimum.

## Great, but why should security club care?
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

3. Get a VM image. (https://www.vagrantup.com/intro/getting-started/)  
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
