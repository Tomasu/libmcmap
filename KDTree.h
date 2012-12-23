#ifndef KDTREE_H_GUARD
#define KDTREE_H_GUARD

class Region;

class KDTree
{
	public:
		KDTree();
		
		Region *getRegion(int x, int z);
};

#endif /* KDTREE_H_GUARD */
