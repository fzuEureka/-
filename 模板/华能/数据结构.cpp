//树状数组 
/*********************/
ll C[N];
int n;
ll lowbit(ll t) { return t&(-t); }
ll getsum(ll x) {
	ll ans=0;
	for(ll i=x;i>0;i-=lowbit(i))
		ans+=C[i];
	return ans;
}
void add(ll x,ll y) { for(ll i=x;i<=n;i+=lowbit(i)) C[i]+=y; }
/*********************/



//线段树
/*********************/
const int N=3e5+5;
const int MAXN=3e5+5;
ll a[MAXN];
struct STree{
	#define ls p<<1 
	#define rs p<<1|1
	#define lls l,mid,ls
	#define rrs mid+1,r,rs
	#define qm (l+r)>>1
	ll ans[MAXN<<2],tag[MAXN<<2];
	inline void push_up(ll p) { ans[p]=min(ans[ls],ans[rs]); }
	void build(ll l,ll r,ll p) {
	    tag[p]=0;
	    if(l==r){ans[p]=a[l];return ;}
	    ll mid=qm;
	    build(lls); build(rrs);
	    push_up(p); }
	inline void up(ll l,ll r,ll p,ll k) {
	    tag[p]=tag[p]+k;
	    ans[p]=ans[p]+k*(r-l+1); }
	inline void push_down(ll p,ll l,ll r) {
	    ll mid=qm;
	    up(lls,tag[p]); up(rrs,tag[p]);
	    tag[p]=0; }
	inline void update(ll nl,ll nr,ll l,ll r,ll p,ll k) {
	    if(nl<=l&&r<=nr) {
	        ans[p]+=k*(r-l+1);
	        tag[p]+=k;
	        return ; }
	    push_down(p,l,r);
	    ll mid=qm;
	    if(nl<=mid)update(nl,nr,lls,k);
		if(nr>mid) update(nl,nr,rrs,k);
	    push_up(p); }
	ll query(ll q_x,ll q_y,ll l,ll r,ll p) {
	    ll res=INF;
	    if(q_x<=l&&r<=q_y)return ans[p];
	    ll mid=qm;
	    push_down(p,l,r);
	    if(q_x<=mid)res=min(res,query(q_x,q_y,lls));
		if(q_y>mid) res=min(res,query(q_x,q_y,rrs));
	    return res; }
}ST;
/*********************/


//主席树 
/*********************/
ll tot;
int getid(int x) {return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
struct STZXTree{
	#define qm (l+r)>>1 
	struct node{ int l,r,sum; } T[N*20];
	void build(int l,int r,int &x){
	    x=++tot;
	    T[x].sum=0;
	    if(l==r)return;
	    int m=(l+r)>>1;
	    build(l,m,T[x].l);
	    build(m+1,r,T[x].r);}
	void updata(int l,int r,int &x,int y,int pos) {
		de(tot);
		tot++;
		T[tot]=T[y];T[tot].sum++;x=tot;
		if(l==r) return ;
		int mid=qm;
		if(pos<=mid) updata(l,mid,T[x].l,T[y].l,pos);
		else updata(mid+1,r,T[x].r,T[y].r,pos);}
	int query(int l,int r,int x,int y,int k) {
		if(l==r) return l;
		int sum=T[T[y].l].sum-T[T[x].l].sum;
		int mid=qm;
		if(k<=sum) return query(l,mid,T[x].l,T[y].l,k);
		else return query(mid+1,r,T[x].r,T[y].r,k-sum);}
}SST;


/*cout << v[SST.query(1,hh,root[l1-1],root[r1],kk)-1] << endl;
int hh=v.size();tot=0;SST.build(1,hh,root[0]);
ff(i,1,n) SST.updata(1,hh,root[i],root[i-1],getid(a[i]));*/
/*********************/
