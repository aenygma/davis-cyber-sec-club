The purpose of this example is a bit more complicated.

1. We'll create a device
2. Assign operations that it can handle
3. Write the code for the functionality of those operations
4. Introduce `put_user`/`get_user` ideas (how to move memory contents from US to Kernel and back)

This gets a bit more complicated but it's building towards what kind of capacities you can expect from a kernel.
The C code itself is fairly simple, similar to what you'd see in userland, with the caveats of using kernel memory and not relying on userspace memory.

## Usage:
After `make`ing the code, you'll need to create the device that you'll be interacting with via `mknod`
* Run `make test`, you'll get a message saying "lkm_example module loaded with device major number: ??"
* Copy that number
* `sudo mknod /dev/lkm_example c ?? 0` where ?? is your number

#### Read from device:
`cat /dev/lkm_example`
`dd if=/dev/lkm_example of=test bs=14 count=100`

#### Write to device:
`echo "LSDJF" >> /dev/lkm_example`
You should expect this to fail, as designed.

Try opening twice.  
Try extending this to do something more interesting. 
Examples: Random number generator?, send data over network, etc

Example and code blantant copied from: https://blog.sourcerer.io/writing-a-simple-linux-kernel-module-d9dc3762c234
