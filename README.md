## SpaceWhale fault-injection

With an increased eye towards 21st-century space exploration, a need has arisen
for frameworks to simulate realistic faults in space-based distributed computer
systems. We propose a new testing framework called  SpaceWhale, based off
the open-source, minimal Xinu operating system. SpaceWhale serves as a platform
for simulating bit flips in different segments of kernel and application memory.

### Setup

1. SSH into a XINU machine (xinu01.cs.purdue.edu). You must have a CS career
account in order to do so.

2. Clone this repository from Github and change into `Xinu-code-BeagleBoneBlack/`

3. Obtain a copy of the Xinu BeagleBoneBlack edition from 
https://github.com/real-xinu/xinu-bbb and copy the `compile` and `cross_compiler`
directories over to SpaceWhale's `Xinu-code-BeagleBoneBlack` directory.

4. To compile the system, run:
```
cd compile/
make clean
make rebuild
make
```

5. Bring up the node using `cs-console beagle160`.

### Multiple nodes

SpaceWhale relies upon multiple nodes for distributed computing. By default,
SpaceWhale boots into the voting scheme configuration and contains the IP
addresses for Xinu backends beagle160, beagle161, beagle162 and beagle163. 
We recommend creating four copies of the `Xinu-code-BeagleBoneBlack` directory,
one for each node. Edit `main.c` such that in three of the nodes (the compute 
nodes), main calls `start_voter_test` with your desired arguments. In the fourth
(beagle163), call `end_voter_test`. Compile and run the machines as specified
above, starting with the arbitration node. Note that after 90 seconds without 
receiving a message, the arbitration node will time out.

To compile the linear configuration, the Xinu machines should each call
`start_test` instead.
