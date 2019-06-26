function [g1,g2] = onecross(gene1,gene2,pos)
  len = numel(gene1);
  g1 = gene1(1:pos);
  g2 = gene2(1:pos);
  g1(pos+1:len) = gene2(pos+1:end);
  g2(pos+1:len) = gene1(pos+1:end);
end
