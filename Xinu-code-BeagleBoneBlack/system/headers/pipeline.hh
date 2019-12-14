/* For including pipeline utilities in the pipeline directory */

int sendinit(char *, uint16, uint16);
void sendmsg(int);

int receiveinit(char *, uint16, uint16, int);
int receivemsg(int);
