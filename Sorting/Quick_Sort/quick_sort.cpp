// (c) Tivole

// Quick Sort Algorithm

void quick_sort(int *array, int i, int j) {
	int l = i, r = j, m, t;
	if(i < j) {
		m = 0.5*(array[l] + array[r]);
		while(l <= r) {
			while(array[l] < m) l++;
			while(array[r] > m) r--;
			if(l <= r) {
				t = array[l];
				array[l] = array[r];
				array[r] = t;
				l++;
				r--;
			}
		}
		quick_sort(array, i, r);
		quick_sort(array, l, j);
	}
	return;
}