import networkx
import networkx as nx
import matplotlib
import matplotlib.pyplot as plt

# Tạo đồ thị
G = nx.DiGraph()

# Thêm cạnh và thuộc tính (dung lượng và chi phí)
G.add_edge(0, 1, capacity=3, cost=1)
G.add_edge(0, 2, capacity=2, cost=2)
G.add_edge(1, 2, capacity=2, cost=5)
G.add_edge(1, 3, capacity=3, cost=1)
G.add_edge(2, 3, capacity=4, cost=3)

# G.add_edge(1, 2, capacity= 1, cost=1)
# G.add_edge(2, 1, capacity= -1, cost=2)
# G.add_edge(2, 3, capacity= 3, cost= 2)
# G.add_edge(3, 2, capacity= -2,cost= 4)
# G.add_edge(3, 1, capacity= -4, cost=3)
# G.add_edge(3, 5, capacity=3,cost= 5)
# G.add_edge(5, 3, capacity=-5, cost=4)
# G.add_edge(3, 4,capacity= 3, cost=2)
# G.add_edge(4, 3, capacity=-2,cost= 2)
# G.add_edge(4, 5, capacity=3, cost=1)
# G.add_edge(6, 3, capacity=-8, cost=1)
# Vẽ đồ thị
pos = nx.spring_layout(G)  # Chọn một disposition để vẽ đồ thị
nx.draw(G, pos, with_labels=True, node_size=700, node_color="skyblue", font_size=8)

# Hiển thị nhãn của cạnh
edge_labels = {(i, j): f"Cap: {G[i][j]['capacity']}, Cost: {G[i][j]['cost']}" for i, j in G.edges()}
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_color='red')

# Hiển thị đồ thị
plt.show()
