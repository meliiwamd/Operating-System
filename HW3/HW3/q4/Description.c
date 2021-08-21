#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h> 
#include<math.h>
#include <time.h>

#define M  1000

//Task Structure
typedef struct Task
{
	int id;
	int value;
	int at_time;
	int unit_count;
	int *unit_id;
} Task;

//Implement Queue
typedef struct Queue
{
	int front;
	int rear;
	int size; 
    unsigned capacity; 
    struct Task* array; 	
} Queue;

//Function for queue creation with specific size
struct Queue* createQueue(unsigned capacity) 
{ 
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0; 
  
    // This is important, see the enqueue 
    queue->rear = capacity - 1; 
    queue->array = (struct Task*)malloc( 
        queue->capacity * sizeof(struct Task)); 
    return queue; 
} 

int isFull(struct Queue* queue) 
{ 
    return (queue->size == queue->capacity); 
} 

int isEmpty(struct Queue* queue) 
{ 
    return (queue->size == 0); 
} 

void enqueue(struct Queue* queue, struct Task item) 
{ 
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1) 
                  % queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
} 

struct Task dequeue(struct Queue* queue)
{ 
    if (isEmpty(queue)) 
        exit; 
    struct Task item = queue->array[queue->front]; 
    queue->front = (queue->front + 1) 
                   % queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 

struct Task front(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        exit; 
    return queue->array[queue->front]; 
} 

struct Task rear(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        exit; 
    return queue->array[queue->rear]; 
} 


void* unit0_function(void* Input)
{
	struct Task *task = (struct Task *)Input;
	sleep(1/2);
	task->value = (task->value + 7) % M;
	printf("Unit 0 Is Done!");
}

void* unit1_function(void* Input)
{
	struct Task *task = (struct Task *)Input;
	sleep(1/2);
	task->value = (task->value * 2) % M;
	printf("Unit 0 Is Done!");
	
}

void* unit2_function(void* Input)
{
	struct Task *task = (struct Task *)Input;
	sleep(1/2);
	task->value =  (task->value * task->value * task->value * task->value * task->value) % M;
	printf("Unit 0 Is Done!");
}

void* unit3_function(void* Input)
{
	struct Task *task = (struct Task *)Input;
	sleep(1/2);
	task->value = task->value - 19;
	printf("Unit 0 Is Done!");
}

void* unit4_function(void* Input)
{
	struct Task *task = (struct Task *)Input;
	sleep(1/2);
	printf("%d task tid: %d value:%d", task->at_time, task->id, task->value);
	printf("Unit 0 Is Done!");
}



//Main
int main(int argc, char const *argv[])
{
	//Read from input and then build each task
	FILE *Input = fopen("simple_example.txt", "r");
	if (Input == NULL)
    {
    	printf("Could not open file ");
        return 1;
    }
    char chunk[128];
    
    struct Queue *buffer = createQueue(3000);
	
	while (fgets(chunk, sizeof(chunk), Input) != NULL)
    {
    	
    	char * token = strtok(chunk, " ");
    	char* array[128];
    	int i = 0;
    	//Task struct should be built
    	struct Task *each_task = (struct Task*)malloc(sizeof(struct Task));
    	while(token != NULL) 
    	{
    		array[i++] = token;
      		token = strtok(NULL, " ");
      		
   		}
    	each_task->id = atoi(array[0]);
    	each_task->value = atoi(array[1]);
    	each_task->at_time = 0;
    	each_task->unit_count = atoi(array[2]);
    	int* units = (int *)malloc(each_task->unit_count * sizeof(int));
    	
    	for(int i = 0; i < each_task->unit_count; i++)
    	{
    		units[i] = atoi(array[i + 3]);
    	}
    	each_task->unit_id = units;
    	
    	
    	//Enqueue in buffer
    	enqueue(buffer, *each_task);
    	
    	//now we have our tasks instructed in our main queue
    	//we should also have 5 more queues for each unit
    	//but unfortunately because of getting my lack of time in  parallel with having lots of job to do,
    	//I wasn't able to implement this question completely
    	//hope I can make that out in next homework and sorry for that 
    	
    }
    fclose(Input);
	
	

	return 0;
}

