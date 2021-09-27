// alsa.c

#include <alsa/asoundlib.h>
#include "alsa.h"

void get_pcm_device_list() {

    char **hints;

    int err = snd_device_name_hint(-1, "pcm", (void***)&hints);
    if (err != 0) {
        exit(1);
    }

    char **n = hints;

    while (*n != NULL) {

        char *name = snd_device_name_get_hint(*n, "NAME");
        char *desc = snd_device_name_get_hint(*n, "DESC");
        char *ioid = snd_device_name_get_hint(*n, "IOID");

        if (name != NULL && 0 != strcmp("null", name)) {
            printf("%s %s %s\n\n", name, desc, ioid);
        }
        n++;
    }

    snd_device_name_free_hint((void**)hints);

}