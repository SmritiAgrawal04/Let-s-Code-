#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main()
{
	int posts, likes, l;
	cin >> posts ;
	cin >> likes;

	vector<int> seq;
	for(int i=0 ;i < likes; i++)
	{
		cin >> l;
		seq.push_back(l);
	}

	vector<pair<int, int>> status;
	status.resize(posts);
	unordered_map<int, int> post_to_index;
	unordered_map<int, int> index_to_post;
	unordered_map<int, int> :: iterator itr1;
	unordered_map<int, int> :: iterator itr2;
	pair<int, int> p;

	for(int i= 0; i < posts; i++)
	{
		index_to_post.insert({i, i+1});
		post_to_index.insert({i+1, i});

		p= make_pair(i,i);
		status[i]= p;
	}

	int temp, index, f, s;

	for(int i= 0; i <likes; i++)
	{
		itr1= post_to_index.find(seq[i]);
		index= itr1->second;

		if(index ==0)
			continue;

		itr2= index_to_post.find(index-1);
		temp= itr2->second;

		itr1->second -=1;
		itr2->second= seq[i];

		itr2= index_to_post.find(index);
		itr2->second= temp;
		itr1= post_to_index.find(temp);
		itr1->second +=1;

		f= status[seq[i]-1].first;
		s= status[seq[i]-1].second;
		f= min(f, index-1);
		s= max(s, index-1);
		p= make_pair(f, s);
		status[seq[i]-1]= p;

		f= status[temp-1].first;
		s= status[temp-1].second;
		f= min(f, index);
		s= max(s, index); 
		p= make_pair(f, s);
		status[temp-1]= p;

	}

	for(int i=0; i< status.size(); i++)
		cout << status[i].first+1 <<"	" << status[i].second+1<< endl;
}