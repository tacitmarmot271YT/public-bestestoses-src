#pragma once
#include "../ipc/tasking/tasks.h"
#define buff_max 25
#define mod %

        char* phys_addr;
        int kern_lvl_lin_addr;
        int server_proc_lin_addr;
        struct IPC* NextMSG;


    // An array is needed for holding the items.
    // This is the shared place which will be
    // access by both process
    // item shared_buff [ buff_max ];

    // Two variables which will keep track of
    // the indexes of the items produced by producer
    // and consumer The free index points to
    // the next free index. The full index points to
    // the first full index.
    int free_index = 0;
    int full_index = 0;


void clear_MSG(int index_to_clear)
{
    if(full_index == index_to_clear)
    {

    }
}

void recieve_MSG()
{


}
