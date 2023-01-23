#define VIDEO_MEMORY    0xb8000
#define WHITE_ON_BLACK  0x0f

void clear_screen()
{
    int screen_size =  80*25;
    int i;
    char *screen = VIDEO_MEMORY;

    for (i = 0; i < screen_size; i++)
    {
        screen[i*2] = ' ';
        screen[i*2+1] = WHITE_ON_BLACK;
    }
}

void main()
{
    char* video_memory = VIDEO_MEMORY;

    clear_screen();
    
    *video_memory = 'X';
}