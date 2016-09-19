#include "curl_struct.h"
#include "printf_color.h"

void init_curl   (void)
{
    //  initialize to memory
    target_data.memory  = malloc(1);
    target_data.size    = 0;

    curl_global_init(CURL_GLOBAL_ALL);

    curl_handle = curl_easy_init();
}

void set_curl_opt(void)
{
    //  set url
    curl_easy_setopt(curl_handle, CURLOPT_URL, TARGET_URL);

    //  send all data to this function
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_memory_callback);
    
    //  write data
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&target_data);

    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

}

int get_curl_data(void)
{
    CURLcode    res;

    res = curl_easy_perform(curl_handle);
    if(res != CURLE_OK)  {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        return  -1;
    } else  {
        printf(GRN "get_date : " RESET "%lu bytes retrieved\n", (long)target_data.size);
    }

    return  0;
}

void del_curl(void)
{
    curl_easy_cleanup(curl_handle);
    free(target_data.memory);
    curl_global_cleanup();
}

size_t   write_memory_callback (void *contents, size_t size, size_t num_of_byte, void *user_p)
{
    size_t  real_size   = size * num_of_byte;

    struct memory   *mem    = (struct memory *)user_p;

    mem->memory = realloc(mem->memory, mem->size + real_size + 1);
    
    if(mem->memory == NULL) {
        printf("not enough memory (realloc returned NULL)\n");
        return  0;
    }
    
    memcpy(&(mem->memory[mem->size]), contents, real_size);
    mem->size               += real_size;
    mem->memory[mem->size]  = 0;

    return  real_size;
}

