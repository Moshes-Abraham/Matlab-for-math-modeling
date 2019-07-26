load data.txt

liu = data([1,3],:); liu = liu'; liu = liu(:);
sha = data([2,4],:); sha = sha'; sha = sha(:);

y = sha .* liu; y = y';
i = 1:24;
t = (12 *i - 4) * 3600;
t1 = t(1); t2 = t(end);
pp = csape(t,y);
xsh = pp.coefs
TL = quadl(@(tt)ppval(pp,tt),t1,t2)
