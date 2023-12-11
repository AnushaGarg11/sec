class bstnode{
	int info;
	bstnode*left;
	bstnode*right;
	public:
		bstnode(int x=0,bstnode*l=0,bstnode*r=0){
			info=x,left=l,right=r;
		}
		friend class bst;
};
class bst{
	bstnode*root;
	int size;
	public:
		bst(){
			root=0;
			size=0;
		}
		void insertion(int x)
		{
			bstnode*p,*q,*parent;
			p=new bstnode(x);
			size++;
			if(root==0){
				root=p;
				return p;
			}
			else{
				q=root;
				while(q!=0){
					if(x<q->info){
						parent=q;
						q=q->left;
					}
					else{
						parent=q;
						q=q->right;
					}
				}
			}
		}
};
