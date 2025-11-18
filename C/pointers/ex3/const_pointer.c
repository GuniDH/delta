/*------------------------------------------------------
* Filename: [const_pointer.c]
* Author: guni deyo haness
-------------------------------------------------------*/

#include <stdio.h>

int main() {
    const int channel=4;
    int new_channel;
    printf("current channel: %d\n", channel);
    printf("Gili give me the new channel!\n");
    scanf("%d", &new_channel);
    int*channel_pointer=(int*)&channel;
    *channel_pointer=new_channel;
    printf("new channel: %d", channel);
    return 0;
}