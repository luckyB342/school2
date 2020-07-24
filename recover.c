#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    //this counter to keep track of how many jpegs found so far
    int counter = 0;

    //allocate a place with 8 characters for inputting the filename
    char filename[8];
    //replace argv[1] with card
    char *card = argv[1];
    //create a pointer called img
    FILE *img;



    //check that if user did not give any inputs, to return
    if(argc !=2)
    {
        printf("Usage: ./recover image \n");
        return 1;
    }

    //open up file and read the file
    FILE *file = fopen(card,"r");
    if(!file)
    {
        printf("Could not open card\n");
        return 1;
    }

    //declare a buffer to put the content that i'm current reading
    unsigned char buffer[512];

    //iterate over contents of the file till the end of the file, since ask to read the element once, if it does not read 512, then it will read it once
    while (fread(buffer, sizeof(buffer), 1, file) == 1)
    {
        //if first 4 bytes of the array are as per the below
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if this is the 1st JPEG that someone is working on
            if(counter == 0)
            {
                //create a new jpeg file
                sprintf(filename, "%03i.jpg", counter);
                counter++;


                //open this new jpeg file
                img = fopen(filename, "w");

                //start writing to this new jpeg
                fwrite(buffer, sizeof(buffer), 1, img);
            }

            //if this is not the 1st JPEG
            else if (counter > 0)
            {
                //close the file at location img that was being written to
                fclose(img);

                //create a new jpeg file
                sprintf(filename, "%03i.jpg", counter);
                counter++;

                //open this new jpeg file
                img = fopen(filename, "w");

                //start writing to this new jpeg, need a number that is based on how many times before the next "start" of the jpeg file
                fwrite(buffer, sizeof(buffer), 1, img);

            }


        }

        //to continue writing if there was a JPEG found before previously
        // else if (counter > 0 && buffer[0] != 0xff )
        // {
        //     //continue writing to this new jpeg
        //     fwrite(buffer, sizeof(buffer), 1, img);
        // }



    }

    //close files
    fclose(img);
    fclose(file);


}