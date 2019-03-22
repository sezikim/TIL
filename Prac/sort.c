#include <stdio.h>
#include "list.h"

int pivot;
int asd;
int compare(const void *a, const void *b) {
	if (asd == 1)
	switch (pivot) {
		case 1:
			return ((car*)a)->retail_price - ((car*)b)->retail_price;
		case 2:
			return ((car*)a)->dealer_cost - ((car*)b)->dealer_cost;
		case 3:
			if (((car*)a)->engine_size > ((car*)b)->engine_size) return 1;
			else return -1;
		case 4:
			return ((car*)a)->weight - ((car*)b)->weight;
		case 5:
			return ((car*)a)->width - ((car*)b)->width;
	}
	else
		switch (pivot) {
		case 1:
			return ((car*)b)->retail_price - ((car*)a)->retail_price;
		case 2:
			return ((car*)b)->dealer_cost - ((car*)a)->dealer_cost;
		case 3:
			if (((car*)b)->engine_size > ((car*)a)->engine_size) return 1;
			else return -1;
		case 4:
			return ((car*)b)->weight - ((car*)a)->weight;
		case 5:
			return ((car*)b)->width - ((car*)a)->width;
	}
}
