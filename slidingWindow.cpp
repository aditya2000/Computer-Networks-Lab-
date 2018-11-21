#include <iostream> 
using namespace std;

int main() {
	int window_size, no_of_frames;

	cout<<"\n Enter the size of window: ";
	cin>>window_size;

	cout<<"\n Enter the no. of frames: ";
	cin>>no_of_frames;

	int frames[no_of_frames];
	cout<<"\n Enter the frames: ";
	for(int i=1; i<=no_of_frames; i++) {
		cin>>frames[i];
	}

	for(int i=1; i<=no_of_frames; i++) {
		if(i%window_size == 0) {
			cout<<"\n"<<frames[i];
			cout<<"\n Acknowledgement of above frames is recieved";
		} else {
			cout<<"\n"<<frames[i];
		}
	}

	if(no_of_frames%window_size != 0) {
		cout<<"\n Acknowledgement of above frames is recieved";
	}
}