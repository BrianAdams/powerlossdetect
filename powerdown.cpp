#include <glib.h>
#include <fcntl.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
static int counter;

static gboolean
onButtonEvent( GIOChannel *channel,
               GIOCondition condition,
               gpointer user_data )
{
    cerr << "onButtonEvent" << endl;
    GError *error = 0;
    gsize bytes_read = 0; 
    const int buf_sz = 1024;
    gchar buf[buf_sz] = {};
    g_io_channel_seek_position( channel, 0, G_SEEK_SET, 0 );
    GIOStatus rc = g_io_channel_read_chars( channel,
                                            buf, buf_sz - 1,
                                            &bytes_read,
                                            &error );
    cerr << "rc:" << rc << "  data:" << buf << endl;
    if (counter == 1) {
      system("shutdown -nh now");
    }
    counter++;
    // thank you, call again!
    return 1;
}

int main( int argc, char** argv )
{
    GMainLoop* loop = g_main_loop_new( 0, 0 );
    counter = 0;
    int fd = open( "/sys/class/gpio/gpio49/value", O_RDONLY | O_NONBLOCK );
    GIOChannel* channel = g_io_channel_unix_new( fd );
    GIOCondition cond = GIOCondition( G_IO_PRI );
    guint id = g_io_add_watch( channel, cond, onButtonEvent, 0 );
    
    g_main_loop_run( loop );
}
