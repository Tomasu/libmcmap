#ifndef KDTREE_H_GUARD
#define KDTREE_H_GUARD

class MCRegion;

class KDTree
{
	public:
		KDTree();
		
		MCRegion *getRegion(int x, int z);
};

#endif /* KDTREE_H_GUARD */
