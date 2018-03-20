// Chromium/base--stl_util源码学习及应用
// http://blog.csdn.net/wangshubo1989/article/details/53558617

#include<iostream>
#include<vector>
#include<algorithm>
#include"stl_util.h"

#define VS_VER  1600

int main()
{
#if _MSC_VER > VS_VER
	std::vector<int> numbers{1, 2, 3, 4, 6};
	std::vector<int> numbers1{ 1, 2, 3 ,4};
#else
	std::vector<int> numbers;
	std::vector<int> numbers1;
	for (int i =0; i < 5 ;i++)
	{
		numbers.push_back(i);
		numbers1.push_back(i);
	}
	numbers.push_back(6);
#endif

	std::cout << "Test STLIsSorted:{1, 2, 3, 4, 6}" << std::endl;
	std::cout << std::boolalpha << webrtc::STLIsSorted(numbers) << std::endl << std::endl;
	

	std::cout << "Test STLSetDifference {1, 2, 3, 4, 6} and { 1, 2, 3 ,4}:" << std::endl;
	std::vector<int> difference_result;
	difference_result = webrtc::STLSetDifference<std::vector<int>, std::vector<int>, std::vector<int>>(numbers, numbers1);
#if _MSC_VER > VS_VER
	for(auto iter: difference_result)
	{
		std::cout << iter << std::endl << std::endl;
	}
#else
	for(std::vector<int>::iterator iter = difference_result.begin();iter !=difference_result.begin();iter++)
#endif
	{
		std::cout << *iter << std::endl << std::endl;
	}

	std::cout << "Test STLSetIntersection {1, 2, 3, 4, 6} and { 1, 2, 3 ,4}:" << std::endl;
	std::vector<int> intersection_result;
	intersection_result = webrtc::STLSetIntersection<std::vector<int>, std::vector<int>, std::vector<int>>(numbers, numbers1);
#if _MSC_VER > VS_VER
	for(auto iter: intersection_result)
	{
		std::cout << iter << " " ;
	}
#else
	for(std::vector<int>::iterator iter = intersection_result.begin();iter !=intersection_result.begin();iter++)
#endif
	{
		std::cout << *iter << " " ;
	}
	std::cout << std::endl;

	std::cout << "Test STLIncludes {1, 2, 3, 4, 6} and { 1, 2, 3 ,4}:" << std::endl;
	std::cout << std::boolalpha << webrtc::STLIncludes(numbers, numbers1) << std::endl << std::endl;


	std::cout << "Test STLClearObject:" << std::endl;
	webrtc::STLClearObject(&numbers);
	std::cout << "vector size:" << numbers.size() << std::endl;
	std::cout << "vector capacity:" << numbers.capacity() << std::endl << std::endl;

	system("pause");
	return 0;
}