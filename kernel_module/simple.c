#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>

struct birthday {
  int day;
  int month;
  int year;
  struct list_head list;
};

static LIST_HEAD(birthday_list);

int simple_init(void) {
  struct birthday *people[3];
  struct birthday *ptr;

  people[0] = kmalloc(sizeof(struct birthday), GFP_KERNEL);
  people[0]->day = 10;
  people[0]->month = 2;
  people[0]->year = 1972;
  INIT_LIST_HEAD(&people[0]->list);
  list_add_tail(&people[0]->list, &birthday_list);

  people[1] = kmalloc(sizeof(struct birthday), GFP_KERNEL);
  people[1]->day = 2;
  people[1]->month = 1;
  people[1]->year = 1978;
  INIT_LIST_HEAD(&people[1]->list);
  list_add_tail(&people[1]->list, &birthday_list);

  people[2] = kmalloc(sizeof(struct birthday), GFP_KERNEL);
  people[2]->day = 8;
  people[2]->month = 3;
  people[2]->year = 1972;
  INIT_LIST_HEAD(&people[2]->list);
  list_add_tail(&people[2]->list, &birthday_list);

  printk(KERN_INFO "Loading Module\n");

  list_for_each_entry(ptr, &birthday_list, list) {
    printk(KERN_INFO "%d/%d/%d\n", ptr->day, ptr->month, ptr->year);
  }

  return 0;
}

void simple_exit(void) {
  struct birthday *ptr, *next;

  printk(KERN_INFO "Removing Module\n");

  list_for_each_entry_safe(ptr, next, &birthday_list, list) {
    printk(KERN_INFO "Deleting %d/%d/%d\n", ptr->day, ptr->month, ptr->year);
    list_del(&ptr->list);
    kfree(ptr);
  }
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

